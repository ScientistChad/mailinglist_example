<?php
/**************************************************************************************************
***************************************************************************************************
*
*---------------PHP Script for seeding mysql database for Mailing List ----------------------------
*
***************************************************************************************************
**************************************************************************************************/
//error_reporting(E_ALL);
//ini_set('display_errors',1);
header('Content-type: text/plain');

include('database.inc');
include('processing.inc');

//parse data from csv into array to prep for database
$filename = '';

$db = new db();
$proc = new processor($filename);

$proc->csvextract();

$db->upload($proc->dataset);

$db->close();
?>

