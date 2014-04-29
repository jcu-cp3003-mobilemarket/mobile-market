<?php
if($username!="guess" ){
	header("location:index.php?myaccount");
}
?>
<div class="login">
<?php 
if($current_page_name == "login"){
?>
<form action="?login" method="" id="loginForm" onsubmit="LoginSubmit();return false;">    
   	<input type="text" name="username" id="username" placeholder="User Name" required="required"/><br/>
    <input type="password" name="password" id="password" placeholder="Password" required="required"/><br/>
	<input type="checkbox" id="login-remember"/><label for="login-remember">Remember me</label><br />
    <input type="submit" value="Login" />
</form>
<?php
}
if($current_page_name == "register"){
?>
<form action="?register" method="" id="registerForm" onsubmit="RegisterSubmit();return false;">    
   	<input type="text" name="username" id="username" placeholder="User Name" onblur="checkUserName()" onfocus="hideAll();" required="required"/><br/>
    <input type="password" name="password" id="password" placeholder="Password" onkeyup="validatePassword()" onfocus="hideAll();" required="required"/><br/>
   	<input type="email" name="email" id="email" placeholder="E-mail" onfocus="hideAll();" onblur="checkEmail()" required="required"/><br/>
    <input type="submit" value="Register"/>
</form>
<?php
}
?>
</div>
<script type="text/javascript">
<?php
if($current_page_name == "login"){
?>
function LoginSubmit(){
	var remember = $('#login-remember:checked').val()?"true":"false";
	$.ajax({
        url: "backend.php",  
        type: "POST",
        data: {loginFormSubmitted:true,username:$('#username').val(),password:$('#password').val(),rememberme:remember},
        cache: false,
        success: function(data) {  
			if (data == "false"){
				Popup.show(null,'username','above center',{'content':'Invalid user name or password!','width':280,
					'style':{'backgroundColor':'red','color':'white','padding':'10px','text-align':'center','border-radius':'20px 0px 20px 0px'}});				
			}
			else{
				window.location.href = "?myaccount";
			}
        }

    });
	return false;
}
<?php
}
if($current_page_name == "register"){
?>
var error = 0;

function checkUserName(){
	if ($('#username').val() == ""){Popup.show(null,'username','above center',{'content':data,'width':170,'style':{'backgroundColor': color,'color':'white','padding':'10px','text-align':'center'}}); return;}
	$.ajax({
			url: "backend.php",  
			type: "POST",
			data: {userNameValidateFormSubmitted:true,username:$('#username').val()},
			cache: false,
			success: function(data) {  
				var color = "red";
				if (data == "Avaliable"){
					color = "green";
					data = "Username avaliable!";
					error = 0;
				}
				else{
					color = "red";
					error  = 1;
				}
				Popup.show(null,'username','above center',{'content':data,'width':170,
						'style':{'backgroundColor': color,'color':'white','padding':'10px','text-align':'center'}});				
			}
		});
}

function checkEmail(){
	if(!isValidEmailAddress($('#email').val())){
		Popup.show(null,'email','below center',{'content':'Invalid email address','width':250,'style':{'backgroundColor': 'red','color':'white','padding':'10px','text-align':'center'}});
		error = 1;
	}
	else{
		$.ajax({
			url: "backend.php",  
			type: "POST",
			data: {checkValidEmailSubmitted:true,email:$('#email').val()},
			cache: false,
			success: function(data) {  
				if(data != "success"){
					Popup.show(null,'email','below center',{'content':data,'width':250,'style':{'backgroundColor': 'red','color':'white','padding':'10px','text-align':'center'}});
					error = 1;
				}

			}
		});
		hideAll();
		error = 0;
	}
}
function isValidEmailAddress(emailAddress) {
    var pattern = /^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
    return pattern.test(emailAddress);
};

function validatePassword(){
	var pass = $('#password').val();
	var msg = "Password strength: ";
	var color = "";
	var score = passwordStrength(pass);
	switch(true){
		case score > 100:
			msg += "Very Strong!";
			color = "blue";
			break;
		case score >80:
			msg += "Strong";
			color = "green";
			break;
		case score >60:
			msg += "Good";
			color = "yellow";
			break;
		default:
			msg += "Weak";
			color = "red";
			break;
	}
	 Popup.show(null,'password','below center',{'content':msg,'width':250,'style':{'backgroundColor': color,'color':'white','padding':'10px','text-align':'center'}});
}

function passwordStrength(pass) {
    var score = 0;
    if (!pass)
        return score;

    // award every unique letter until 5 repetitions
    var letters = new Object();
    for (var i=0; i<pass.length; i++) {
        letters[pass[i]] = (letters[pass[i]] || 0) + 1;
        score += 5.0 / letters[pass[i]];
    }

    // bonus points for mixing it up
    var variations = {
        digits: /\d/.test(pass),
        lower: /[a-z]/.test(pass),
        upper: /[A-Z]/.test(pass),
        nonWords: /\W/.test(pass),
    }

    variationCount = 0;
    for (var check in variations) {
        variationCount += (variations[check] == true) ? 1 : 0;
    }
    score += (variationCount - 1) * 10;

    return parseInt(score);
}

function hideAll(){
	$('.PopupDiv').hide();
}
function RegisterSubmit(){
	if(error == 0){
		$.ajax({
			url: "backend.php",  
			type: "POST",
			data: {regiserFormSubmitted:true,username:$('#username').val(),password:$('#password').val(),email:$('#email').val()},
			cache: false,
			success: function(data) {  
				if(data == 'success'){
					window.location.href = "?myaccount";
				}
			}
		});
	}
	return false;
}
<?php
}
?>
</script>