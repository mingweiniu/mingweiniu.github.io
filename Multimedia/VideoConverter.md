List all subtile
$ ffprobe -loglevel error -select_streams s -show_entries stream_tags=language -of csv=p=0 input_video.mkv

Extract subtile
$ ffmpeg -i input_video.mkv -map 0:s:0 output_video.srt

convert mkv to mp4 with other resolution
$ ffmpeg -i input_video.mkv -r 60 -s hd720 output_video.mp4
