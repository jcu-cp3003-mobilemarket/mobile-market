<?php
include("databaseconnect.inc");
$page_name = get_current_page_name();
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<link rel="stylesheet" type="text/css" href="css/header.css"/>
<link rel="stylesheet" type="text/css" href="css/notification.css" />
<link rel="stylesheet" type="text/css" href="css/admin.css"/>
<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.5.1/jquery.min.js"></script>
<script src="js/ttw-notification-menu.js" type="text/javascript"></script>
<script src="js/jquery-ui-1.8.14.custom.min.js" type="text/javascript"></script>
<title>Admin</title>
</head>

<body>
<?php 
include("adminpanel.inc");
?>
<div id="wrapper">
<?php
switch($page_name){
	case "dashboard":
		include("dashboard.inc");
		break;
	case "contact":
		include("contact.inc");
		break;
	case "announcement":
		include("announcement.inc");
		break;
	case "images":
		include("images.inc");
		break;
}
?>
</div>

<script type="text/javascript">
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
	
		   var notifications = new $.ttwNotificationMenu({
        notificationList:{
            anchor:'item',
            offset:'0 15'
        }
    });


    notifications.initMenu({
        projects:'#projects',
        tasks:'#tasks',
		clents:'#clients',
		messages:'#messages',
		hello:'#hello'
    });
	notifications.createNotification({category:'hello',message:'sample',icon:'images/notification-bg.png'});
	notifications.createNotification({category:'hello',message:'sample',icon:'images/notification-bg.png'});
		notifications.createNotification({category:'hello',message:'sample',icon:'images/notification-bg.png'});

</script>

</body>
</html>