import os

def apply(config, args):
    basename = 'beetleadventurerac'
    if os.path.exists(f'build/{basename}.us.bin'):
        version = 'us'

    config['baseimg'] = f'baserom.us.z64'
    config['myimg'] = f'build/{basename}.us.z64'
    config['mapfile'] = f'build/{basename}.us.map'
    config['source_directories'] = ['src', 'include']
