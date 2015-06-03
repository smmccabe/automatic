<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-02
 * Time: 7:47 PM
 */

class entity {
  protected $db;
  protected $id;
  protected $x, $y;
  protected $type;

  function __construct (mysqli $db) {
    $this->db = $db;
  }

  public function run() {

  }
}