<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-01
 * Time: 9:04 PM
 */

require_once('database.inc');

for($x = 0; $x < 100; $x++){
  for($y = 0; $y < 100; $y++){
    $result = $db->query("SELECT * FROM grid WHERE x = $x AND y = $y");
    if($result->num_rows <= 0){
      $db->query("INSERT INTO grid(x, y, type) VALUES($x, $y, 'grass')");
    }
  }
}

