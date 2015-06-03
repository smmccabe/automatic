<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-01
 * Time: 9:05 PM
 */

require_once('database.inc');

$test = new space_elevator($db);
$test->run();

