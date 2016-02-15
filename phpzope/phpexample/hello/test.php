<?php

dl('hello.so');

function say()
{
print "==\n";
$i=0;
while($i<3)
{
echo $i."\n";
$i++;
sleep($i);
}
}
echo hello_world();
//sleep(10);
?>
