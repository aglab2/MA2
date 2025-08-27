import os
import soundfile as sf

directory = '/run/media/admin/SSD/git/MA2/sound/samples/instruments' 

for filename in os.listdir(directory):
    if filename.lower().endswith(('.aiff', '.aif')):
        filepath = os.path.join(directory, filename)
        try:
            with sf.SoundFile(filepath) as f:
                print(f"{filename}: {f.samplerate} Hz")
        except Exception as e:
            print(f"Error reading {filename}: {e}")

