--TEST--
Test for bug #885: missing validation point returned by strchr in xdebug_error_cb.
--FILE--
<?php
throw new Exception("long message ".str_repeat('.', 10240));
?>
--EXPECTF--
Fatal error: Uncaught exception 'Exception' with message 'long message ...................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................................... in %sbug00885.php on line 2
