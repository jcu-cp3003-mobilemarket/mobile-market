<?php 	
session_start();
include("databaseconnect.inc");
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"> 
  <head data-gwd-animation-mode="proMode">
    <title>The Mobile Market</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="generator" content="Google Web Designer 1.0.4.0305">
    <link rel="stylesheet" type="text/css" href="css/style.css"/>
    <?php
	include("importjs.inc");
	?>
	
  </head>
  
  <body>
	  <?php
	  include("header.inc");
	  ?>  
    <div id="wrapper">
      <?php
	  include("menu.inc");
	  ?>
      <?php
	        if(get_current_page_name() == "home")
			  include("homepage.inc");

	  		if(get_current_page_name() == "apple"){
				$producer = "Apple";
				include("product.inc");
			}
			if(get_current_page_name() == "samsung"){
				$producer = "Samsung";
				include("product.inc");
			}
			if(get_current_page_name() == "others"){
				$producer = "Others";
				include("product.inc");
			}
			if(get_current_page_name() == "feedback"){
				include("feedback.inc");
			}
			if(get_current_page_name() == "login"){
				include("login.inc");
			}
			if(get_current_page_name() == "myaccount"){
				include("myaccount.inc");
			}
			if(get_current_page_name() == "daily"){
				include("daily.inc");
			}
	  ?>
    </div>
    <?php
	include("sidebarcart.inc");
	?>
	<?php 
	include("footer.inc");
	?>
  </body>

</html>