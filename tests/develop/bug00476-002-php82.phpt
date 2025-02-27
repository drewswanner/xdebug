--TEST--
Test for bug #476: Exception chanining doesn't work (>= PHP 8.2)
--INI--
xdebug.mode=develop
xdebug.dump.GET=
xdebug.dump.SERVER=
xdebug.show_local_vars=0
--SKIPIF--
<?php
require __DIR__ . '/../utils.inc';
check_reqs('PHP >= 8.2');
?>
--FILE--
<?php

function a()
{
   throw new Exception('First exception');
}

function b()
{
	try {
		a();
	} catch(Exception $e) {
	   throw new Exception('Second exception', 0, $e);
	}
}

function c()
{
	try {
		b();
	} catch(Exception $e) {
	   throw new Exception('Third exception', 0, $e);
	}
}

function d()
{
	try {
		c();
	} catch(Exception $e) {
	   throw new Exception('Fourth exception', 0, $e);
	}
}

d();

echo "DONE\n";
?>
--EXPECTF--
Fatal error: Uncaught%sFirst exception%sin %sbug00476-002-php82.php%s%d
Stack trace:
#0 %sbug00476-002-php82.php(11): a()
#1 %sbug00476-002-php82.php(20): b()
#2 %sbug00476-002-php82.php(29): c()
#3 %sbug00476-002-php82.php(35): d()
#4 {main}

Next Exception: Second exception in %sbug00476-002-php82.php:13
Stack trace:
#0 %sbug00476-002-php82.php(20): b()
#1 %sbug00476-002-php82.php(29): c()
#2 %sbug00476-002-php82.php(35): d()
#3 {main}

Next Exception: Third exception in %sbug00476-002-php82.php:22
Stack trace:
#0 %sbug00476-002-php82.php(29): c()
#1 %sbug00476-002-php82.php(35): d()
#2 {main}

Next Exception: Fourth exception in %sbug00476-002-php82.php on line 31

Exception: Fourth exception in %sbug00476-002-php82.php on line 31

Call Stack:
%w%f %w%d   1. {main}() %sbug00476-002-php82.php:0
%w%f %w%d   2. d() %sbug00476-002-php82.php:35
