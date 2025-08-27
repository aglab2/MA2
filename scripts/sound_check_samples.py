import os
import soundfile as sf
import resampy

script_dir = os.path.dirname(os.path.realpath(__file__))
directory = script_dir + '/../sound/samples/instruments' 
target_rate = 22050

for filename in os.listdir(directory):
    if not filename.lower().endswith(('.aiff', '.aif')):
        continue

    filepath = os.path.join(directory, filename)
    try:
        with sf.SoundFile(filepath) as f:
            if f.samplerate <= target_rate:
                continue
            print(f"File {filename} has a sample rate of {f.samplerate}, resampling...")

            data_resampled = resampy.resample(f.read(), f.samplerate, target_rate, axis=0)
            base, _ = os.path.splitext(filename)
            output_path = os.path.join(directory, f"{base}_LOW.aiff")

            sf.write(output_path, data_resampled, target_rate, format="AIFF")

    except Exception as e:
        print(f"Error reading {filename}: {e}")
