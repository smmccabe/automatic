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

if(isset($_GET['view_x'])){
  $view_x = $db->real_escape_string($_GET['view_x']);
}
else{
  $view_x = 80;
}

if(isset($_GET['view_y'])){
  $view_y = $db->real_escape_string($_GET['view_y']);
}
else{
  $view_y = 40;
}
?>

<html>
<head>
  <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>
<?php
$result = $db->query("SELECT * FROM grid WHERE x >= $x AND x < $x+$view_x AND y >= $y AND y < $y+$view_y ORDER BY y asc, x asc");
if ($result->num_rows > 0) {
  while($row = $result->fetch_assoc()) {
    if (!isset($y)) {
      $y = $row['y'];
    }
    elseif ($y != $row['y']){
      $y = $row['y'];
      print '<div class="clear"></div>';
    }
    print '<div class="grid ' . $row['type'] . '"></div>';
  }
}

?>

</body>
</html>
