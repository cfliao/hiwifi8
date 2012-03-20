<?php
header('Content-Type: application/json;charset=UTF-8');
$raw =  file_get_contents('php://input', 'r');
//echo $raw;

$cwmp = json_decode($raw);

$Body = $cwmp->CWMP->Body;
$Inform = $Body->Inform;

var_dump($Inform->DeviceId);

?>
