<?php
/**
 * Created by PhpStorm.
 * User: Shawn
 * Date: 2015-06-02
 * Time: 8:00 PM
 */

class worker extends entity {

  function __construct (mysqli $db) {
    parent::__construct($db);
  }

  public function run () {
    parent::run();
  }
}