import com.google.gson.JsonArray;
import com.google.gson.JsonParser;
import java.nio.charset.StandardCharsets;

public class Example1 {
	public static void main(String[] args)
	{
		String geekPortalUserDetails
			= "[{\"firstName\":\"GeekA\",\"Posts\":\"100\"},
		{
			\"firstName\":\"GeekB\",\"Posts\":\"150\"},
			{
				\"firstName\":\"GeekC\",\"Posts\":\"50\"}]";

				// string to byte[]
				byte[] userDetailsBytes
					= geekPortalUserDetails.getBytes(
						StandardCharsets.UTF_8);

				// converting the bytes to String
				String userDetailsBytesToStrings
					= new String(userDetailsBytes,
								StandardCharsets.UTF_8);
				JsonParser jsonParser = new JsonParser();

				// As the byte array details contains
				// JSONArray elements, we need to parse the
				// output in the form of JsonArray
				JsonArray jsonArrayOutput
					= (JsonArray)jsonParser.parse(
						userDetailsBytesToStrings);
				System.out.println("Output : "
								+ jsonArrayOutput);
			}
		}
