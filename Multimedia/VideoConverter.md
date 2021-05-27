# Video Commands

## List all subtile
$ ffprobe -loglevel error -select_streams s -show_entries stream_tags=language -of csv=p=0 input_video.mkv  

## Extract subtile
$ ffmpeg -i input_video.mkv -map 0:s:0 output_video.srt

## convert mkv to mp4 with other resolution  
$Input = "X1.mkv", "X2.mkv"  
$Output = "X1.mp4", "X2.mp4"  
for ($i = 0; $i -lt $Input.Length; $i++)  
{  
    ffmpeg -i $Input[$i] -s hd720 -c:v libx264 -cq:v 23 -c:a aac -strict -2 $Output[$i]  
}  
