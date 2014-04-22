<?php
$iserror= false;
if(isset($_POST['username'])){
	$username = $_POST['username'];
	$password = $_POST['password'];
	$remember = isset($_POST['rememberme'])?true:false;
	if(check_user_login($username,$password)){
		session_regenerate_id();
		$_SESSION['username'] = $username;
		header("location:?myaccount");
	}
	$iserror = true;
}
?>
<div class="login <?php if($iserror) echo "login-error" ?>">
<form action="?login" method="post">
   	<input type="text" name="username" placeholder="User Name"/><br/>
    <input type="password" name="password" placeholder="********"/><br/>
    <input type="checkbox" id="login-remember" name="rememberme[]" value="true"/><label for="login-remember">Remember me</label><br />
    <input type="submit" value="Login"/>
</form>
</div>
<?php
if($iserror) include("loginerror.include");
?>