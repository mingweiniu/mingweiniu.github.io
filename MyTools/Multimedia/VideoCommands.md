# Video Commands

## List all subtile
```
$ ffprobe -loglevel error -select_streams s -show_entries stream_tags=language -of csv=p=0 input_video.mkv
```

## Extract subtile
```
$ ffmpeg -i input_video.mkv -map 0:s:0 output_video.srt
```

## convert mkv to mp4 with other resolution
```
$Input = "X1.mkv", "X2.mkv" 
$Output = "X1.mp4", "X2.mp4"
for ($i = 0; $i -lt $Input.Length; $i++)
{
    ffmpeg -i $Input[$i] -s hd720 -c:v libx264 -crf 23 -c:a aac -strict -2 $Output[$i]
}
```

## Merge image and audio into video
```
ffmpeg -loop 1 -i "input.png" -i "input.wav" -shortest -acodec copy result.mkv
```

## tar all folder
```
foreach($file in Get-ChildItem .)
{
  $name = $file.Name
  tar cvf "$name.tar" $name
}
```
## Rename files
```
$Input = "X1.mkv", "X2.mkv"
$Output = "X1.mp4", "X2.mp4"  
for ($i = 0; $i -lt $Input.Length; $i++)
{
    Rename-Item -Path $Input[$i] -NewName $Output[$i]
}
```
