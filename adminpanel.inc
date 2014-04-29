<nav>
<a class="logo" href="#">Mobile Market</a>
<a class="toggleview" href="#"></a>
<ul class="ttw-notification-menu">
    <li id="projects" class="notification-menu-item"><a href="">Test</a></li>
    <li id="tasks" class="notification-menu-item"><a href="">Test</a></li>    
    <li id="messages" class="notification-menu-item"><a href="" >Test</a></li>
    <li id="clients" class="notification-menu-item"><a href="">Test</a></li>
    <li id="hello" class="notification-menu-item"><a href="" >Test</a></li>
	<li class="notification-menu-item"><a href="#">Logout</a></li>
</ul>
</nav>
<aside>
&nbsp;
<ul>
<li class="frist-list"></li>
<li <?php if($page_name == "dashboard")echo "class = 'active'"?>><a href="?dashboard">Dashboard</a></li>
<li <?php if($page_name == "contact")echo "class = 'active'"?>><a href="?contact">Contact</a></li>
<li <?php if($page_name == "announcement")echo "class = 'active'"?>><a href="?announcement">Announcement</a></li>
<li <?php if($page_name == "calendar")echo "class = 'active'"?>><a href="?calendar">Calendar</a></li>
<li <?php if($page_name == "images")echo "class = 'active'"?>><a href="?images">Images</a></li>
<li class="end-list"></li>
</ul>
</aside>