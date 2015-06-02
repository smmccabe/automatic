<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-01
 * Time: 9:06 PM
 */

$db = new mysqli('localhost', 'automatic', '', 'automatic');

if ($db->connect_error) {
  die("Connection failed: " . $db->connect_error);
}