import os
import soundfile as sf

directory = '../sound/samples/instruments' 

for filename in os.listdir(directory):
    if filename.lower().endswith(('.aiff', '.aif')):
        filepath = os.path.join(directory, filename)
        try:
            with sf.SoundFile(filepath) as f:
                print(f"{filename}: {f.samplerate} Hz")
        except Exception as e:
            print(f"Error reading {filename}: {e}")

