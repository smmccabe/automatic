<?php

class entity {
  protected $db;
  protected $id;
  protected $x, $y;
  protected $type;
  protected $completion;

  function __construct (mysqli $db) {
    $this->db = $db;
  }

  public function load($id) {
    $result = $this->db->query("SELECT * FROM grid WHERE id=$id");
    if($result->num_rows > 0) {
      $row = $result->fetch_assoc();

      $this->id = $row['id'];
      $this->x = $row['x'];
      $this->y = $row['y'];
      $this->completion = $row['completion'];
    }
  }

  public function save(){
    if($this->id){
      $this->db->query("UPDATE grid SET x=$this->x, y=$this->y, completion=$this->completion WHERE id=$this->id");
    }
    else if(isset($x) && isset($y) && isset($type)) {
      if ($this->db->query("INSERT INTO grid(x, y, type, completion) VALUES($this->x, $this->y, '$this->type', 0)") === TRUE) {
        $this->id = $this->db->insert_id;
        $this->x = 0;
        $this->y = 0;

      } else {
        echo "Error: " . $this->db->error;
      }
    }
  }

  public function delete(){
    if($this->id){
      $this->db->query("DELETE FROM grid WHERE id=$this->id");
    }
  }

  public function run() {

  }
}