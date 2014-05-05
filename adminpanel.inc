<?php
?>
<nav>
<a class="logo" href="#">Mobile Market</a>
<a class="toggleview" href="#"></a>
<ul class="notification">
<li><a href="#">Logout</a></li>
<li class="dropdown-menu"><a href="#">Notification</a><span class="label">4</span>
	<ul class="dropdown-list">
    <li class="header">aaaa</li>
    <li>aaaa</li>
    </ul>
</li>

</ul>
</nav>
<aside>
&nbsp;
<ul>
<li class="frist-list"></li>
<li class="active"><a href="#" class="menu-item dashboard">Dashboard</a></li>
<li ><a href="#" class="menu-item contact">Contact</a></li>
<li ><a href="#" class="menu-item announcement">Announcement</a></li>
<li ><a href="#" class="menu-item calendar">Calendar</a></li>
<li ><a href="#" class="menu-item images">Images</a></li>
<li class="end-list"></li>
</ul>
</aside>
<script type="text/javascript">
setInterval(function() {
	var date = new Date();
  $.ajax({
	  url:"backend.php",
	  type:"post",
	  cache:false,
	  data:{},
	  success: function(data){
		  
	  }
	  });
}, 1000);//call every minutes
$(document).click(function(e){
	if(!$('.dropdown-menu').is(e.target) && $('.dropdown-menu').has(e.target).length === 0){
		$('.dropdown-menu').removeClass('open');
	}else{
		if($('.dropdown-menu').hasClass('open')){
			$('.dropdown-menu').removeClass('open');
		}
		else{
			$('.dropdown-menu').addClass('open');
		}
	}
	});


</script>