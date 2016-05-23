<?php

$zope = new PHPZope();

$zope->readPickle("/usr/local/apache2/phpzope/newdoc.txt");

$zo = $zope->returnPickleFile();


foreach ($zo as $key => $value)
{
	print "key";
	print $key;
	print "<br/>";
	print "value";
	if ($key == "theMemo")
	{
		foreach ($value as $key1 => $val1)
		{
		    print "    key: ";
		    print $key1;
		    print "<br/>";
		    print "    value: ";
		    foreach ($val1 as $key2 => $val2)
		    {
			print $key2;
			print $val2;
		    }
		    print "<br/>";
		}
	}
	else
	{
		print_r($value);
	}
	print "<br/><br/>";
}



?>
