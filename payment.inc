<?php
if($username == "guess" ){
	header("location:index.php");
}
if(isset( $_SESSION['cart'])) {
?>
<script>
var error=0;
$(document).ready(function(){
  $("#master-card").click(function(){
    $("#card-type").val("master");
	$("#card-info-table").css("background-color","rgb(51, 153, 204)");
	$("#purchase-btn").css("background-color","rgb(51, 153, 204)");
  });
  $("#visa-card").click(function(){
    $("#card-type").val("visa");
	$("#card-info-table").css("background-color","rgb(146, 205, 0)");
	$("#purchase-btn").css("background-color","rgb(146, 205, 0)");
  });
});
function CardNumberValidate(){
	error = 0;
	var inputcardnum = document.getElementById('card-number').value;
	if(inputcardnum.split("+").length>1) error =1;
	if(inputcardnum.split(".").length>1) error =1;
	var splittedInput = inputcardnum.split("-");
	var cardnumber = "";
	if(splittedInput.length == 4){
		$.each(splittedInput,function(index,fourdigits){
			if(!$.isNumeric(fourdigits) || fourdigits.length !=4){
				error=1;
			}
			cardnumber+=fourdigits;
			});
	}
	else if(splittedInput.length == 1 && $.isNumeric(splittedInput) && inputcardnum.length == 16){
		cardnumber = splittedInput;
	}
	else{
		error = 1;
	}
	if(error > 0){
		$('#card-number').addClass('invalid-input');
	}
	else{
		$('#card-number').removeClass('invalid-input');
	}
}
function check(){
	CardNumberValidate();
	if(error > 0){
		return false;
	}
}
</script>
  <div class="card-info">
  Total amount: $100
      <span id="master-card">Master</span>
      <span id="visa-card">Visa</span>
    <form action="?complete" id="card-information-form" onsubmit="return check();">
	<input type="hidden" id="card-type" value="master"/>
    <table id="card-info-table">
    <tr>
    	<td>Card Number</td>
        <td>Expire On</td>
        <td>Security<br/> Number</td>
        <td>Card Holder's Name</td>
    </tr>

    <tr>
    	<td><input type="text" name="card-number" id="card-number" placeholder="xxxx-xxxx-xxxx-xxxx" required="required" onblur="CardNumberValidate()"/></td>
        <td><select><?php for($i = 1; $i<=12;$i++){ echo "<option value='".$i."'>".$i."</option>"; }?></select>
        	<select><?php for($i = date("Y");$i <=date("Y")+10;$i++){
				echo "<option  value='".$i."'>".$i."</option>";} ?>
                </select>
        </td>
        <td><input type="text" placeholder="xxx" style="width:50px;" required="required"  pattern="[0-9]{3}"/></td>
        <td><input type="text" placeholder="Card Holder's Name" required="required"/></td>
    </tr>
    </table>
	<input id="purchase-btn" type="submit" value="Purchase"/>
    </form>
  </div>

<?php
}
else{
?>
<div style="position:relative;top:200px;margin-left:auto;margin-right:auto; width:300px; margin-top:0px;">
<img src="images/empty-cart.png" alt="No item"  />
</div>
<?php
}
?>