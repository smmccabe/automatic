<?php

require_once 'entity.inc';

class space_elevator extends entity {
  private $completed;

  function __construct (mysqli $db) {
    parent::__construct($db);

    $this->type = 'space_elevator';

    $result = $db->query("SELECT * FROM grid WHERE type = 'space_elevator'");
    if($result->num_rows > 0){
      $row = $result->fetch_assoc();

      $this->id = $row['id'];
      $this->x = $row['x'];
      $this->y = $row['y'];
      $this->completed = $row['completed'];
    }
    else{
      if ($db->query("INSERT INTO grid(x, y, type, completion) VALUES(0, 0, 'space_elevator', 0)") === TRUE) {
        $this->id = $db->insert_id;
        $this->x = 0;
        $this->y = 0;

        print "space elevator created <br />";
      } else {
        echo "Error: " . $db->error;
      }
    }
  }

  public function run () {
    parent::run();

    if($this->completed < 100) {
      $this->completed++;
    }
  }

  private function look_for_workers() {
    $result = $this->db->query("SELECT * FROM grid WHERE type = 'worker'");
    if($result->num_rows > 0){

    }
    else{
      new worker($this->db);
    }
  }
}
