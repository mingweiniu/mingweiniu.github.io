youtube-dl -U
$collection = "url1", "url2", "url3"
foreach ($VideoURL in $collection)
{
youtube-dl --format bestvideo+bestaudio --write-thumbnail -o '[%(upload_date)s]%(title)s-%(id)s.%(ext)s' --cookies="cookiejar.txt" $VideoURL
}
