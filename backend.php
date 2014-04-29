<?php
require("databaseconnect.inc");
if(isset($_POST['loginFormSubmitted']) && isset($_POST['username']) && isset($_POST['password'])){
	$username = $_POST['username'];
	$password = $_POST['password'];
	$remembere = $_POST['rememberme'];
	if(check_user_login($username,$password)){
		$_SESSION['username'] = $username;
		if($remembere == "true"){
			setcookie("username", $username, time()+60*60*24*30*12);
			setcookie("password", $password, time()+60*60*24*30*12);
			}
		echo "true";
	}
	else{
		echo "false";
	}
}
if(isset($_POST['TokenFormSubmitted'])){
	if(isset($_POST['token'])){
		set_token($_SESSION['username'],$_POST['token']);
	}
	if(isset($_POST['type'])){
		add_coupon($_SESSION['username'],$_POST['type']);
	}
	$arr = get_coupon($_SESSION['username']);
	echo json_encode($arr);
	unset($arr);
}
if(isset($_POST['checkValidEmailSubmitted'])){
	if(is_email_exist($_POST['email'])){
		echo $_POST['email']." is already used.";
	}
	else{
		echo "success";
	}
}
if(isset($_POST['userNameValidateFormSubmitted'])){
	if(is_username_exist($_POST['username']) || ($_POST['username'] == "guess")){
		echo "'".$_POST['username']."' is not avaliable";
	}
	else{
		echo "Avaliable";
	}
}
if(isset($_POST['regiserFormSubmitted']) && isset($_POST['username']) && isset($_POST['password'])){
	if(!is_username_exist($_POST['username']) && !is_email_exist($_POST['email'])){
		add_new_customer($_POST['username'],$_POST['password'],$_POST['email']);
		add_to_dailychance($_POST['username']);
		session_regenerate_id();
		$_SESSION['username'] = $_POST['username'];
		echo "success";
	}
}
if(isset($_POST['addToWishlistSubmitted']) && isset($_SESSION['username']) && isset($_POST['productID'])){
	if(add_to_wishlist($_SESSION['username'],$_POST['productID'])){
		echo "1";
	}
	else{
		echo "0";
	}
}
if(isset($_POST['removeFromWishlistSubmitted'])&& isset($_POST['code'])){
	remove_from_wishlist($_SESSION['username'],$_POST['code']);
	echo $_POST['code'];
}
if(isset($_POST['addToFavouriteSubmitted']) && isset($_SESSION['username']) && isset($_POST['productID'])){
	$arr=array();
	if(is_already_favourite($_SESSION['username'],$_POST['productID'])){
		remove_from_favourite($_SESSION['username'],$_POST['productID']);
		$arr["isFavourite"] = "false";
	}
	else{
		add_to_favourite($_SESSION['username'],$_POST['productID']);
		$arr['isFavourite'] = "true";
	}
	$arr['amount'] = total_favourite_amount($_POST['productID']);
	echo json_encode($arr);
	unset($arr);
}
if(isset($_POST['FeedbackEdited'])){
	update_page_data('feedback','feedback',$_POST['text']);
	$arr = get_page_data('feedback');
	echo $arr['content'];
	unset($arr);

}
if(isset($_POST['oldURL']) && isset($_POST['newURL'])){
	if(isset($_FILES["newURL"]) && $_FILES["newURL"]["error"]== UPLOAD_ERR_OK)
{
	############ Edit settings ##############
	$UploadDirectory	= 'css/uploads/'; //specify upload directory ends with / (slash)
	##########################################
	
	/*
	Note : You will run into errors or blank page if "memory_limit" or "upload_max_filesize" is set to low in "php.ini". 
	Open "php.ini" file, and search for "memory_limit" or "upload_max_filesize" limit 
	and set them adequately, also check "post_max_size".
	*/
	
	//check if this is an ajax request
	if (!isset($_SERVER['HTTP_X_REQUESTED_WITH'])){
		die();
	}
	
	
	//Is file size is less than allowed size.
	if ($_FILES["newURL"]["size"] > 5242880) {
		die("File size is too big!");
	}
	
	//allowed file type Server side check
	switch(strtolower($_FILES['newURL']['type']))
		{
			//allowed file types
            case 'image/png': 
			case 'image/gif': 
			case 'image/jpeg': 
			case 'image/pjpeg':
			case 'text/plain':
			case 'text/html': //html file
			case 'application/x-zip-compressed':
			case 'application/pdf':
			case 'application/msword':
			case 'application/vnd.ms-excel':
			case 'video/mp4':
				break;
			default:
				die('Unsupported File!'); //output error
	}
	
	$File_Name          = strtolower($_FILES['newURL']['name']);
	$File_Ext           = substr($File_Name, strrpos($File_Name, '.')); //get file extention
	$Random_Number      = rand(0, 9999999999); //Random number to be added to name.
	$NewFileName 		= $Random_Number.$File_Ext; //new file name
	
	if(move_uploaded_file($_FILES['newURL']['tmp_name'], $UploadDirectory.$NewFileName ))
	   {
		die('Success! File Uploaded.');
	}else{
		die('error uploading File!');
	}
	
}
else
{
	die('Something wrong with upload! Is "upload_max_filesize" set correctly?');
}
}
?>