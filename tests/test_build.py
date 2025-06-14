import os
import subprocess
import tempfile

ROOT = os.path.dirname(os.path.dirname(__file__))
BUILD_DIR = os.path.join(ROOT, 'build_test')


def test_cmake_build():
    if os.path.exists(BUILD_DIR):
        subprocess.run(['rm', '-rf', BUILD_DIR], check=True)
    subprocess.run(['cmake', '-S', ROOT, '-B', BUILD_DIR], check=True)
    subprocess.run(['cmake', '--build', BUILD_DIR], check=True)
    exe = os.path.join(BUILD_DIR, 'csp_main')
    assert os.path.exists(exe)

    default_fw = os.path.join(ROOT, 'firmware', 'firmware.bin')
    os.makedirs(os.path.dirname(default_fw), exist_ok=True)
    with open(default_fw, 'wb') as f:
        f.write(b'\x00\x01\x02\x03')

    out = subprocess.check_output([exe], cwd=ROOT).decode()
    assert 'ADPCM processing stub' in out

    with tempfile.NamedTemporaryFile(delete=False) as tmp:
        tmp.write(b'\x05\x06')
        tmp.flush()
        env = dict(os.environ)
        env['FIRMWARE_PATH'] = tmp.name
        out_env = subprocess.check_output([exe], env=env, cwd=ROOT).decode()
    assert 'ADPCM processing stub' in out_env

    os.remove(default_fw)
