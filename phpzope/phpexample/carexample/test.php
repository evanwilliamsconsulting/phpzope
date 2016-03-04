<?php

dl('vehicles.so');

$oCar = new Car(1);
$oCar->shift(1);

print_r($oCar);

print_r(get_loaded_extensions());

?>
