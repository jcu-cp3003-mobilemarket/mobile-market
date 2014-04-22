<header>
	&nbsp; My Account
		<ul>
<?php
if(isset($_SESSION['username'])){
			echo "<li><a href=\"?myaccount\">Setting</a></li>";
			echo "<li><a href=\"#\">Cart</a></li>";
			echo "<li><a href=\"#\">Wish List</a></li>";
			echo "<li><a href=\"?daily\">Daily Chance</a></li>";
			echo "<li><a href=\"signout.php\">Sign Out</a></li>";
}
else{
			echo "<li><a href=\"?login\">Sign in</a></li>";
			echo "<li><a href=\"#\">Register</a></li>";

}
?>		

		</ul>
</header>    
