<?php
if(isset($_POST['TokenFormSubmitted'])){
	set_token($_SESSION['username'],$_POST['token']);
	add_coupon($_SESSION['username'],$_POST['type']);
}
if(isset($_POST['ClaimSubmitted'])){
	
}
$coupons = get_coupon($_SESSION['username']);
$token = 0;
if(strtotime("-1 day") > strtotime($coupons['token'])){
	$token = 1;
}

?>
<table class="daily-play">
<tr>
<td>
<img src="images/blue-coupon.png" alt="Blue Coupon" class="coupon"/>x40
<img src="images/green-coupon.png" alt="Green Coupon" class="coupon"/>x30
<img src="images/yellow-coupon.png" alt="Yellow Coupon" class="coupon"/>x25 = 5%
<br/><br />
You have <?php echo $token;?> daily token to spin the wheel<br /><br />
<?php
if($token == 1){
	echo "<input type=\"button\" onclick=\"sendFlash()\" id=\"tokenbtn\" value=\"Use Token\" /><br /><br />";
}
?>

Your Inventory:
<br />
<img src="images/blue-coupon.png" alt="Blue Coupon" class="coupon"/>x<?php echo$coupons['blue'];?> <br />
<img src="images/green-coupon.png" alt="Green Coupon" class="coupon"/>x<?php echo$coupons['green'];?>  <br />
<img src="images/yellow-coupon.png" alt="Yellow Coupon" class="coupon"/>x<?php echo$coupons['yellow'];?>  <br />
<br />
<form action="?daily" method="post">
<input type="hidden" name="ClaimSubmitted" value="1" />
<input type="submit" value="Claim"/><br/>
</form>
<form id="tokenform" action="?daily" method="post">
<input type="hidden" name="TokenFormSubmitted" value="1"/>
<input type="hidden" name="token" id="newtoken" value="<?php echo $coupons['token'];?>"/>
<input type="hidden" name="type" id="type"  />
</form>

</td>
<td >
    <embed class="flash-game" src="luckydraw.swf" id="flash" width="450" height="450" align="middle" allowScriptAccess="always" type="application/x-shockwave-flash"/>
</td>
</tr>
</table>
<script language="javascript" type="text/javascript" >
function evaluate(Txt) {
	$('#type').val(Txt);
	$('#tokenform').submit();
}
function sendFlash() {
	$('#tokenbtn').hide();
	flash.receiveJS();
	var d = new Date();
	var Y = d.getFullYear();
	var M = d.getMonth()+1;
	var D = d.getDate();
	var H = d.getHours();
	var m = d.getMinutes();
	var s = d.getSeconds();
 	var currentDateTime = Y+"-"+M+"-"+D+" "+H+":"+m+":"+s;
	$('#newtoken').val(currentDateTime);
}

</script>
