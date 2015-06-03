<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-02
 * Time: 8:00 PM
 */

class worker extends entity {

  function __construct (mysqli $db, $id, $x, $y) {
    parent::__construct($db);

    $this->type = 'worker';

    if($id){
      //load by id
      $result = $db->query("SELECT * FROM grid WHERE id=$id");
    }
    else if(isset($x) && isset($y)){
      //create or load at x/y
      $db->query("INSERT INTO gird(x, y, type) VALUES($x, $y, 'worker')");
      $this->id = $db->insert_id;
      $this->x = $x;
      $this->y = $y;
    }
  }

  public function run () {
    parent::run();
  }
}