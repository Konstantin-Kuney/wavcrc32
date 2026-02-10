#!/bin/bash
# Run wavcrc32 for all .wav files in the current directory
# script by Konstantin Kuney 10.02.2026
for file in *.wav; do
    echo "Processing file: $file"
    wavcrc32 "$file"
done
