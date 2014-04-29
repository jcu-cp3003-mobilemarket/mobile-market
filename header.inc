<header>
	&nbsp; My Account
		<ul>
<?php
if(!isset($_SESSION['username'])){
			echo "<li><a href=\"?login\" class=\"pageslide-animation\">Sign in</a></li>";
			echo "<li><a href=\"?register\"  class=\"pageslide-animation\">Register</a></li>";

}

else{
			echo "<li><a href=\"?myaccount\" class=\"pageslide-animation\">Setting</a></li>";
			echo "<li><a href=\"?cart\" class=\"pageslide-animation\">Cart</a></li>";
			echo "<li><a href=\"?wishlist\" class=\"pageslide-animation\">Wish List</a></li>";
			echo "<li><a href=\"?daily\" class=\"pageslide-animation\">Daily Chance</a></li>";
			echo "<li><a href=\"signout.php\" class=\"pageslide-animation\">Sign Out</a></li>";
}
?>		

		</ul>
</header>    
