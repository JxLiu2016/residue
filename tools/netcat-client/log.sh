REQ=$(php create_request-log.php connection.json)
#echo Sending...
#echo $REQ
printf "$REQ\r\n\r\n" | nc `cat host` 8778
