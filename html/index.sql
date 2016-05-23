<?php
error_reporting(E_ALL);

$username="root";
$password="ptH3984z";
$database="nhp";

mysql_connect(localhost,$username,$password);

mysql_select_db($database);

$query = "select state from object_state where zoid=6400;";

$result = mysql_query($query);

print_r($result);

$num = mysql_numrows($result);

$i = 0;

while ($i < $num) {
    $state = mysql_result($result,$i,"state");
    $i++;
}

mysql_close();	

$handle = fopen("/usr/local/apache2/phpzope/test.txt","cw");

fwrite($handle,$state);

fclose($handle);

?>
<html>
<head>
    <title>PHPZope</title>
</head>
<body>
    <h1>TEST</h1>
    <h2><?php echo "$state" ?></h2>
</body>
</html>
