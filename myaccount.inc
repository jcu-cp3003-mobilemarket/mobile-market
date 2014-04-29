<?php
if($username=="guess" ){
	header("location:index.php");
}
$username = $_SESSION['username'];
if(isset($_POST['PersonalInfoSubmitted'])){
	update_customer_data($_SESSION['username'],$_POST['firstname'],$_POST['lastname'],$_POST['gender'],$_POST['dob'],$_POST['contact'],$_POST['postalcode'],$_POST['address']);
}
if(isset($_POST['AccountSettingSubmitted'])){
	if(check_user_login($_SESSION['username'],$_POST['oldpassword'])){
		update_customer_email($_SESSION['username'],$_POST['email']);
	}
	else{
		$errorexist = true;
		$errormsg = "Incorrect password!";
	}
}
$personal_info = get_customer_data($username);
?>
<div id="personal-info-error" style="display:<?php echo isset($errorexist)?"block":"none"?>" >
<?php echo isset($errorexist)?$errormsg:"";?></div>
<div class="personal-content">
    <div class="personal-image">
		<div class="gold-line"></div>
        <img src="images/profile.png" alt="Profile"/>
        <div class="change-profile-photo" id="change-profile-photo"><a href="#" id="change_profile">Change Profile</a></div>
        <script type="text/javascript">
		</script>
    </div>
    <div class="vertical-gray-line">
    </div>
        <table class="personal-info">
        <tr>
            <td class="gold-bg" colspan="2">Personal Information </td>
        </tr>
        <form action="?myaccount" method="post" id="personalInfo">
        <input type="hidden" name="PersonalInfoSubmitted" value="1" />
        <tr>
             <td>First Name</td><td><input type="text" required="required" pattern=".{1,25}" name="firstname" placeholder="First Name" value="<?php echo $personal_info['firstname'];?>"/></td>
        </tr>
        <tr>
             <td>Last Name</td><td><input type="text" required="required" pattern=".{1,25}" name="lastname" placeholder="Last Name" value="<?php echo $personal_info['lastname'];?>"/></td>
        </tr>
        <tr>
            <td>Date of Birth</td><td><input type="date" name="dob" value="<?php echo $personal_info['dob'];?>" required="required" />
                                  </td>
        </tr>
        <tr>
            <td>Gender</td>
            <td><input name="gender" required="required" type="radio" id="gender-male" <?php if($personal_info['gender']=="Male") echo "checked";?> value="Male"/><label for="gender-male">Male</label>
            <input name="gender" type="radio" id="gender-female" <?php if($personal_info['gender']=="Female") echo "checked";?> value="Female"/><label for="gender-female">Female</label>
            </td>
        </tr>
        <tr>
            <td>Contacts</td><td><input type="text" required="required" pattern="[0-9]*" placeholder="123456" name="contact" value="<?php echo $personal_info['contact'];?>"/></td>
        </tr>
        <tr>
            <td>Postal Code</td><td><input type="text" required="required" pattern="[0-9]*" placeholder="123456" name="postalcode" value="<?php echo $personal_info['postalcode'];?>"/></td>
        </tr>
        <tr>
            <td>Address</td><td><textarea placeholder="Enter your Address" required="required"><?php echo $personal_info['address'];?></textarea><input type="hidden" name="address" id="address"/></td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" value="Submit" class="gold-bg"/></td>
        </tr>
        </form>
        <form action="?myaccount" method="post" onsubmit="return validatePassword()" id="account-setting">
         <input type="hidden" name="AccountSettingSubmitted" value="1" />
        <tr>
            <td class="blue-bg" colspan="2">Account Setting</td>
        </tr>
        <tr>
            <td>Login ID</td><td><input type="text" value="<?php echo $_SESSION['username'];?>" disabled="disabled"/></td>
        </tr>
        <tr>
            <td>Email</td><td><input  type="email" name="email" required="required" value="<?php echo $personal_info['email'];?>"/></td>
        </tr>
        <tr>
            <td>Old Password</td><td><input pattern=".{1,25}" required="required" type="password" name="oldpassword"/></td>
        </tr>
        <tr>
            <td>New Password</td><td><input pattern=".{1,25}" type="password" id="newpassword1"/></td>
        </tr>
        <tr>
            <td>Varify Password</td>
            <td><input pattern=".{1,25}" type="password" id="newpassword2"/>
            <span id="pass-varify-error" style="color:red;display:none;"><br/>Please verify your password!</span>
            </td>
        </tr>
        <tr>
            <td colspan="2"><input type="submit" value="Submit" class="blue-bg"/></td>
        </tr>
        <input type="hidden" name="newpassword" id="newpassword"/>
        <input type="file" name="photo" id="photo" style="display:none" />
        </form>
        </table>
</div>
<script type="text/javascript">
$('#personalInfo').submit(function(){
	$('#address').val($('textarea').val());
	});
function validatePassword(){
	if($('#newpassword1').val()!=$('#newpassword2').val()){
		$('#pass-varify-error').show();
		return false;
	}
	$('newpassword').val($('#newpassword1').val());
}
$('#change_profile').click(function(){$('#photo').click()});
</script>