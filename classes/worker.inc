<?php

class worker extends entity {

  function __construct (mysqli $db, $id, $x = null, $y = null) {
    parent::__construct($db);

    $this->type = 'worker';

    if(isset($id)){
      parent::load($id);
    }
    else if(isset($x) && isset($y)){
      //create or load at x/y
      $this->x = $x;
      $this->y = $y;
      $this->type = 'worker';
      parent::save();
    }
  }

  public function run () {
    parent::run();
  }
}