<?php
include 'basic.php';

$basic = new Basic;

$basic->a = 1;
$basic->b = 2;

print $basic->result();

echo serialize($basic);
?>
