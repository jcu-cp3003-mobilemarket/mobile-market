<html>
<head>
<?php
session_start();
$_SESSION = array();

session_destroy();
?>
<meta http-equiv="refresh" content="2; url=index.php?home">
<title>Sign Out</title>
</head>
<body>
Signing Out...
</body>
</html>