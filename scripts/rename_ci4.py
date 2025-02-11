import os
import sys

if __name__ == "__main__":
    directory = sys.argv[1]
    for filename in os.listdir(directory):
        old_path = os.path.join(directory, filename)
        name, ext = filename.rsplit(".")
        new_path = os.path.join(directory, f"{name}.rgba32.{ext}")
        os.rename(old_path, new_path)
