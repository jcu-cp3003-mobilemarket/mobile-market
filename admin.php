<?php
include("databaseconnect.inc");
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" type="text/css" href="css/header.css"/>
<link rel="stylesheet" type="text/css" href="css/notification.css" />
<link rel="stylesheet" type="text/css" href="css/admin.css"/>
<link href="css/fullcalendar/fullcalendar.css" rel="stylesheet" type="text/css" />
<link href="css/fullcalendar/fullcalendar.print.css" rel="stylesheet" type="text/css" media='print' />

<script src="http://ajax.googleapis.com/ajax/libs/jquery/2.0.2/jquery.min.js"></script>
<script src="js/jquery-ui-1.10.3.min.js" type="text/javascript"></script>
<script type="text/javascript" src="js/ckeditor/ckeditor.js" ></script>

<title>Admin</title>
</head>

<body>
<?php 
include("adminpanel.inc");
?>
<div id="wrapper">
<?php
include("dashboard.inc");
?>
</div>

<script type="text/javascript">
$('aside').height($('#wrapper').height()+150);
$('.toggleview').click(function(){
	if(!$('aside').hasClass('page-SlideOut')){
		$('aside').removeClass('page-SlideIn');
		$('aside').addClass('page-SlideOut');
		$('#wrapper').css('left','0px');
		var w = $('#wrapper').width();
		$('#wrapper').css('width',(w+200)+'px');
		var alltag = $('#wrapper').children();
		alltag.css('width',(w+200)+'px');
		alltag.addClass('slow-transition');
		}
	else{
		$('aside').removeClass('page-SlideOut');
		$('aside').addClass('page-SlideIn');
		var w = $('#wrapper').width();
		$('#wrapper').css('left','200px');
		$('#wrapper').css('width',(w-200)+'px');
		var alltag = $('#wrapper').children();
		alltag.css('width',(w-200)+'px');
		}
	});

var pageURL = "dashboard.inc";
$('.dashboard').click(function(){pageURL = "dashboard";});
$('.contact').click(function(){pageURL = "contact";});
$('.images').click(function(){pageURL = "images";});
$('.announcement').click(function(){pageURL = "announcement";});
$('.calendar').click(function(){pageURL = "calendar";});
$('.menu-item').click(
	function(){
		$('.active').removeClass('active');
		$('.'+pageURL+'').parent().addClass('active');
		$('#wrapper').addClass("page-SlideOut");
		$('#wrapper').removeClass("page-SlideIn").delay(100);
		
		$.ajax({
			type:"GET",
			url:pageURL+".inc",
			success:function(data){
				$('#wrapper').html(data);
				$('#wrapper').removeClass("page-SlideOut");
				$('#wrapper').addClass("page-SlideIn");
				}
		});
		
	});

</script>

</body>
</html>