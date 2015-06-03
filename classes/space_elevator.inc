<?php

require_once 'entity.inc';

class space_elevator extends entity {
  function __construct (mysqli $db) {
    parent::__construct($db);

    $this->type = 'space_elevator';

    $result = $db->query("SELECT id FROM grid WHERE type = 'space_elevator'");
    if($result->num_rows > 0){
      $row = $result->fetch_assoc();
      parent::load($row['id']);
    }
    else{

    }
  }

  public function run () {
    parent::run();

    if($this->completion < 100) {
      $this->completion++;

      print "COMPLETION: " . $this->completion;
    }
    else{
      if($worker = $this->look_for_workers()){
        print "worker found";
      }
      else{
        new worker($this->db, null, $this->x+1, $this->y);
        print "Creating Worker";
      }
    }

    parent::save();
  }

  private function look_for_workers() {
    $result = $this->db->query("SELECT id FROM grid WHERE type = 'worker'");
    if($result->num_rows > 0){
      $row = $result->fetch_assoc();
      return new worker($this->db, $row['id']);
    }
  }
}
