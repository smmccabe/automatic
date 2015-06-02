<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-01
 * Time: 9:05 PM
 */

require_once('database.inc');

$result = $db->query("SELECT * FROM grid WHERE type = 'space_elevator'");
if($result->num_rows > 0){
  print "space elevator exists <br />";
}
else{
  if ($db->query("INSERT INTO grid(x, y, type, completion) VALUES(0, 0, 'space_elevator', 0)") === TRUE) {
    $last_id = $db->insert_id;
    print "space elevator created <br />";
  } else {
    echo "Error: " . $db->error;
  }
}