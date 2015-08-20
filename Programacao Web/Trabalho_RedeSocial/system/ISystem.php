<?php

interface ISystem{

	public static function start();
	public static function getBase();
	public static function getUrl($index);
	public static function getController();
	public static function getAction();


}