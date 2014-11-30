<?php
$con=mysqli_connect("localhost","USERNAME","PASSWORD","DATABASE_NAME") or die(mysql_error());
// $con contains your mysql connection object

// Now to exectue a query create a query object
$query=mysqli_query($con,"select * from table_name where ravi = 'kutta'");

// $query has the output of query.. And to loop over it do this

while($row=mysqli_fetch_assoc($query)){
	echo 'Name = '.$row['name'].'<br>';
}

// $row is an array that contains one row of database