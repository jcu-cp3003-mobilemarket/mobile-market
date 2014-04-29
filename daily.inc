<?php
if($username=="guess" ){
	header("location:index.php");
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
<span id="tokendisplay">You have <?php echo $token;?> daily token to spin the wheel</span><br /><br />
<?php
if($token == 1){
	echo "<input type=\"button\" onclick=\"sendFlash()\" id=\"tokenbtn\" value=\"Use Token\" /><br /><br />";
}
?>

Your Inventory:
<br />
<img src="images/blue-coupon.png" alt="Blue Coupon" class="coupon"/><span id="blue-coupons">x <?php echo$coupons['blue'];?> </span><br />
<img src="images/green-coupon.png" alt="Green Coupon" class="coupon"/><span id="green-coupons">x <?php echo$coupons['green'];?></span><br />
<img src="images/yellow-coupon.png" alt="Yellow Coupon" class="coupon"/><span id="yellow-coupons">x <?php echo$coupons['yellow'];?></span><br />
<br />

</td>
<td >
    <embed class="flash-game" src="luckydraw.swf" id="flash" width="450" height="450" align="middle" allowScriptAccess="always" type="application/x-shockwave-flash"/>
</td>
</tr>
</table>
<script language="javascript" type="text/javascript" >
var newtoken = '<?php echo $coupons['token'];?>';
function evaluate(Txt) {
	$.ajax({
	url: "backend.php",  
	type: "POST",
	data: {TokenFormSubmitted:true,type:Txt},    
	cache: false,
	success: function(data) {
		data = JSON.parse(data);
		$('#blue-coupons').html('x '+data['blue']);
		$('#green-coupons').html('x '+data['green']);
		$('#yellow-coupons').html('x '+data['yellow']);
	}
    });

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
	newtoken = currentDateTime;
	$.ajax({
	url: "backend.php",  
	type: "POST",
	data: {TokenFormSubmitted:true,token:newtoken},    
	cache: false,
	success: function(data) {  
		data = JSON.parse(data);
		$('#tokendisplay').html("Now, you used token. Click 'Play' to spin the wheel -->>");
	}
    });
}

</script>
