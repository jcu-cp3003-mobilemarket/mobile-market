<html>
<head>
<?php
session_start();
$_SESSION = array();
setcookie("username","",time()-3600);
setcookie("password","",time()-3600);
session_destroy();
?>
<meta http-equiv="refresh" content="1; url=index.php?home">
<title>Sign Out</title>
</head>
<body>
Signing Out...
</body>
</html>