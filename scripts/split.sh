#!/bin/bash

INPUT="$1"

ROWS=4
COLS=4

# Get image dimensions
WIDTH=$(magick identify -format "%w" "$INPUT")
HEIGHT=$(magick identify -format "%h" "$INPUT")

echo "Image dimensions: ${WIDTH}x${HEIGHT}"

# Calculate tile dimensions
TILE_WIDTH=$((WIDTH / COLS))
TILE_HEIGHT=$((HEIGHT / ROWS))

echo "Tile dimensions: ${TILE_WIDTH}x${TILE_HEIGHT}"

# Create output directory
mkdir -p tiles

# Cut the image into 16 tiles
for row in $(seq 0 $((ROWS - 1))); do
  for col in $(seq 0 $((COLS - 1))); do
    X=$((col * TILE_WIDTH))
    Y=$((row * TILE_HEIGHT))
    magick "$INPUT" -crop "${TILE_WIDTH}x${TILE_HEIGHT}+${X}+${Y}" +repage "tiles/tile_${row}_${col}.png"
  done
done
