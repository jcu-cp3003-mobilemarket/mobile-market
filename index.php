<?php 	
include("databaseconnect.inc");
$current_page_name = get_current_page_name();
?>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"> 
  <head data-gwd-animation-mode="proMode">
    <title>The Mobile Market</title>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
    <meta name="generator" content="Google Web Designer 1.0.4.0305">
    <link rel="stylesheet" type="text/css" href="css/style.css"/>
    <link rel="stylesheet" type="text/css" href="css/header.css"/>
    <script type='text/javascript' src='js/popup.js'></script>
	<script type='text/javascript' src='http://ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js'></script>
    <script type="text/javascript">
	$(document).ready(function(){
		$('.pageslide-animation').click(function(){$('body').removeClass('page-SlideIn');$('body').addClass('page-SlideOut');});
	});
	</script>
  </head>
  
  <body class="page-SlideIn">
	  <?php
	  include("header.inc");
	  ?>  
    <div id="wrapper">
      <?php
	  include("menu.inc");
	  ?>
      <?php
	  switch($current_page_name){
		case "apple":
				$producer = "Apple";
				include("product.inc");
				break;
		case "samsung":
				$producer = "Samsung";
				include("product.inc");
				break;
		case "others":
				$producer = "Others";
				include("product.inc");
				break;
		case "feedback":
				include("feedback.inc");
				break;
		case "login":
				include("login.inc");
				break;
		case "myaccount":
				include("myaccount.inc");
				break;
		case "daily":
				include("daily.inc");
				break;
		case "cart":
				include("cart.inc");
				break;
		case "payment":
				include("payment.inc");
				break;
		case "wishlist":
				include("wishlist.inc");
				break;
		case "register":
				include("login.inc");
				break;
		default;
		include("homepage.inc");
	  }
	  ?>
    </div>

    <?php
	if(request_to_show_sidebar_cart()){
		include("sidebarcart.inc");
	}
	?>
	<?php 
	include("footer.inc");
	?>
  </body>

</html>