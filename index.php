<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-01
 * Time: 7:28 PM
 */

require_once('database.inc');

if (isset($_GET['x'])) {
  $x = $db->real_escape_string($_GET['x']);
}
else {
  $x = 0;
}

if (isset($_GET['y'])) {
  $y = $db->real_escape_string($_GET['y']);
}
else{
  $y = 0;
}

if(isset($_GET['viewport'])){
  $viewport = $db->real_escape_string($_GET['viewport']);
}
else{
  $viewport = 200;
}
?>

<html>
<head>
  <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<?php
$result = $db->query("SELECT * FROM grid WHERE x >= $x AND x < $x+$viewport AND y >= $y AND y < $y+$viewport ORDER BY X,Y");
if ($result->num_rows > 0) {
  while($row = $result->fetch_assoc()) {
    if (!isset($x)) {
      $x = $row['x'];
    }
    elseif ($x != $row['x']){
      $x = $row['x'];
      print '<div class="clear"></div>';
    }
    print '<div class="' . $row['type'] . '"></div>';
  }
}

?>

</body>
</html>
